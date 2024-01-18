# Image Conversion from RGB to Grayscale

## Overview
This C program takes an input BMP image file in RGB format and converts it into a grayscale image. The output is saved as a new BMP file. The program reads the header of the input image, extracts information such as width, height, and bit depth, and then performs the RGB to grayscale conversion on the image data.

## Usage
1. Compile the program using a C compiler. For example, using GCC:
   ```bash
   gcc your_program_name.c -o output_executable_name
   ```
2. Run the compiled executable, providing the input and output file paths as command-line arguments.

## Input
- The input BMP file path is hard-coded in the program and set to `"C:\\Users\\Poojitha Sai\\Downloads\\sample_bmp.bmp"`. Modify the path as needed.

## Output
- The output grayscale BMP file is saved with the file path `"C:\\Users\\Poojitha Sai\\Downloads\\sample_bmp_output.bmp"`.

## Code Explanation
1. The program opens the input BMP file in binary read mode (`"rb"`) and the output BMP file in binary write mode (`"wb"`).
2. It reads the 54-byte header from the input file and writes it to the output file.
3. Extracts information from the header, including image width, height, and bit depth.
4. Allocates a buffer to store the RGB data for each pixel in the image.
5. Converts each pixel from RGB to grayscale using the formula `gray = 0.3 * red + 0.59 * green + 0.11 * blue`. 
6. Writes the resulting grayscale pixel values to the output file.

## Note
- The program assumes that the input image is in BMP format with a 24-bit color depth (8 bits per channel).
- Refer [this link](https://www.baeldung.com/cs/convert-rgb-to-grayscale) to understand the conversion formula better.

## Disclaimer
- The program does not handle all possible BMP file formats or error conditions. It is a basic example and may need modifications for broader use cases.
