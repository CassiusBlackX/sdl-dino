use crate::config::{SCREEN_WIDTH, SCREEN_HEIGHT};

const A: u32 = 1664525;
const C: u32 = 1013904223;
const SEED: u32 = 0;

pub fn write_to_vga(address: usize, value: usize, framebuffer: &mut [u32]) {
    if address < (SCREEN_WIDTH * SCREEN_HEIGHT) as usize {
        framebuffer[address] =  value as u32;
    }
}

#[allow(arithmetic_overflow)]
pub fn rand() -> u32 {
    let seed = A | SEED + C;
    let mut result = seed ^ (seed >> 16);
    result = result.wrapping_mul(0x85ebca6b);
    result = result ^ (result >> 13);
    result = result.wrapping_mul(0xc2b2ae35);
    result = result ^ (result >> 10);
    result
}