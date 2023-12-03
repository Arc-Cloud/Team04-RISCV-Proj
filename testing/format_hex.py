import sys

def format_hex(hex_string):
    # Add a space between pairs of characters
    formatted_string = ' '.join([hex_string[i:i+2] for i in range(0, len(hex_string), 2)])
    return formatted_string

def convert_hex_file(input_file_path, output_file_path):
    with open(input_file_path, 'r') as input_file, open(output_file_path, 'w') as output_file:
        for line in input_file:
            formatted_line = format_hex(line.strip())
            output_file.write(formatted_line + '\n')

    print(f"Conversion complete. Formatted hex saved to {output_file_path}")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python convert_hex.py <input_file> <output_file>")
        sys.exit(1)

    input_file_path = sys.argv[1]
    output_file_path = sys.argv[2]

    convert_hex_file(input_file_path, output_file_path)
