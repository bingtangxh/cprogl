from PIL import Image
import os

input_folder = "ilovepdf_images-extracted"
output_folder = "flipped_images"

os.makedirs(output_folder, exist_ok=True)

for filename in os.listdir(input_folder):
    if filename.lower().endswith(('.jpg', '.png', '.jpeg')):
        img_path = os.path.join(input_folder, filename)
        img = Image.open(img_path)
        flipped_img = img.transpose(Image.FLIP_TOP_BOTTOM)
        flipped_img.save(os.path.join(output_folder, filename))
