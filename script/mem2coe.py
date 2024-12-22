import sys

def bin_to_coe(bin_file, coe_file):
    with open(bin_file, "rb") as f:
        data = f.read()

    with open(coe_file, "w") as f:
        f.write("memory_initialization_radix=16;\n")
        f.write("memory_initialization_vector=\n")
        for i in range(0, len(data), 4):
            word = data[i:i+4]
            # 如果字节数不足4个，用0填充
            if len(word) < 4:
                word = word.ljust(4, b'\x00')
            f.write(f"{int.from_bytes(word, byteorder='little'):08x}")
            if i < len(data) - 4:
                f.write(",\n")
        f.write(";")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python mem2coe.py <input.bin> <output.coe>")
        sys.exit(1)

    bin_to_coe(sys.argv[1], sys.argv[2])
