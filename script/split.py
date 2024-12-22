def split_ram_to_coe(input_file, output_files):
    """
    Split a 32-bit binary data file into four 8-bit COE files.

    Args:
        input_file (str): Path to the input binary file.
        output_files (list of str): List of output file names for the 8-bit COE files.
    """
    # Open input file and read content
    with open(input_file, 'rb') as f:
        data = f.read()

    # Initialize buffers for each output file
    ram_parts = [bytearray() for _ in range(4)]

    # Iterate through 32-bit (4-byte) chunks
    for i in range(0, len(data), 4):
        word = data[i:i+4]
        if len(word) < 4:
            # Pad incomplete words with zeros
            word = word.ljust(4, b'\x00')
        ram_parts[0].append(word[0])  # Most significant byte
        ram_parts[1].append(word[1])
        ram_parts[2].append(word[2])
        ram_parts[3].append(word[3])  # Least significant byte

    # Write each buffer to its corresponding output COE file
    for idx, output_file in enumerate(output_files):
        with open(output_file, 'w') as f:
            f.write("memory_initialization_radix=16;\n")
            f.write("memory_initialization_vector=\n")
            hex_data = [f"{byte:02X}" for byte in ram_parts[idx]]
            f.write(",\n".join(hex_data) + ";\n")

# Input and output file configuration
input_file = "./ram.mem"
output_files = ["ram0.coe", "ram1.coe", "ram2.coe", "ram3.coe"]

# Split the RAM file into COE files
split_ram_to_coe(input_file, output_files)