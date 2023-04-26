#Katelyn Choudhari

#A program that reads a text file with photo file
#names and modifies the files from a .jpg to .txt

#gets user file
photo_file = input("Enter the photo file name: ")

#open and reads user file
with open (photo_file,'r') as f:
    x = f.readlines()

#swaps .jpg with .txt for file extensions
text_file = [photo_file.strip().replace("_photo.jpg", "_info.txt") for photo_file in x]

#prints modified photo file names
for photo_file in text_file:
    print(photo_file)
