mod entity;
mod trex;
mod cactus;
mod text;
mod config;
mod utils;
// mod game;

// use crate::game::start;

use std::time::Duration;

use bytemuck::cast_slice;



use sdl2::pixels::PixelFormatEnum;
use sdl2::event::Event;
use sdl2::keyboard::Keycode;
// use sdl2::pixels::Color;

use crate::entity::Entity;
use crate::trex::Trex;
use crate::cactus::Cactus;
use crate::text::Text;
use crate::config::*;

static mut frame_buffer: [u32; SCREEN_WIDTH * SCREEN_HEIGHT] = [0; SCREEN_WIDTH * SCREEN_HEIGHT];

fn render_game(canvas: &mut sdl2::render::Canvas<sdl2::video::Window>, texture: &mut sdl2::render::Texture, framebuffer: &[u32]) {
    let framebuffer_u8: &[u8] = cast_slice(framebuffer);
    texture.update(None, framebuffer_u8, 4 * SCREEN_WIDTH as usize).unwrap();
    canvas.clear();
    canvas.copy(&texture, None, None).unwrap();
    canvas.present();
}

fn main() -> Result<(), String> {
    let sdl_context = sdl2::init()?;
    let video_subsystem = sdl_context.video()?;

    let window = video_subsystem
        .window("rust-sdl2 demo: Video", SCREEN_WIDTH as u32, SCREEN_HEIGHT as u32)
        .position_centered()
        .opengl()
        .build()
        .map_err(|e| e.to_string())?;

    let mut canvas = window.into_canvas().build().map_err(|e| e.to_string())?;
    let texture_creator = canvas.texture_creator();
    let mut texture = texture_creator.create_texture_streaming(PixelFormatEnum::ARGB8888, SCREEN_WIDTH as u32, SCREEN_HEIGHT as u32)
    .map_err(|e| e.to_string())?;

    let mut trex = Trex::new(10, 101);
    let mut cactus = Cactus::new(10, 30);
    let mut text = Text::new(10, 30);

    canvas.clear();
    canvas.present();

    let mut event_pump = sdl_context.event_pump()?;

    let frame_duration = 1000 / FPS;

    'running: loop {
        let frame_start = std::time::Instant::now();
        for event in event_pump.poll_iter() {
            match event {
                Event::Quit { .. } => break 'running,
                Event::KeyDown { keycode: Some(Keycode::Escape), .. } => break 'running,
                Event::KeyDown { keycode: Some(Keycode::Up), .. } => {
                    trex.jump();
                }
                Event::KeyDown { keycode: Some(Keycode::Down), .. } => {
                    cactus.start();
                    trex.start();
                    text.start();
                }
                _ => {}
            }
        }
        unsafe {
            frame_buffer.fill(0);
        
            text.update(&mut frame_buffer);
            trex.update(&mut frame_buffer);
            cactus.update(&mut frame_buffer);
        }


        if cactus.outofbound() {
            cactus.reset();
            cactus.start();
        }

        if trex.crashed(&cactus) {
            trex.reset();
            cactus.reset();
            text.reset();
        }

        unsafe {
            render_game(&mut canvas, &mut texture, &frame_buffer);
        }

        let frame_end = std::time::Instant::now();
        let frame_time = frame_end.duration_since(frame_start).as_millis() as usize;
        if frame_time < frame_duration {
            std::thread::sleep(Duration::from_millis(frame_time as u64));
        }
    }

    Ok(())
}