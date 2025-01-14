pub trait Entity {
    fn start(&mut self);
    fn reset(&mut self);
    fn update(&mut self, frame_buffer: &mut [u32]);

    fn get_top(&self) -> i32;
    fn get_left(&self) -> i32;
    fn get_width(&self) -> usize;
    fn get_height(&self) -> usize;
    
}