# What is this?
This is an attempt to make a neural network ENTIRELY in C. Specifically, the goal of this "simple" neural network is to locate the 
x, y coordinates of a quadrilateral within a given 150x30 image.

# Where (are the important details)?
Nowhere. When I'm done, the very unprofessional and unserious message(s) that you see below this line will be replaced with something more professional, with some cool 
maths, images, a video, maybe a better description, and some other things. This is (somewhat) a bit satirical because it's cathartic for me. Also because this project
is still ongoing, so there's like not much stuff to look at anyways. Duh.

# Why?
Because blockmakerpedi. (Also because it is cool).
</br>
...
</br>
Ok maybe I lied, there is an ulterior motive. More will be revealed as the project continues. Here are a few of my "nefarious" ideas ranked in order of importance to me:
1. Update the curriculum of the introductory course of C programming in my college; yes I know I'm delusional but I really do think the intro course to C can teach AI
2. Learn Neural networks in the big 26 and during the age of AI (AGI IS UPON US), yes I know I'm a couple years behind but better late than not
3. Learn how to write better programs in C, because currently I do a lot of Python but not a lot of low-level programming
4. Test my sanity and how long I can hold on to it while making this project
5. ~~Create a bot for the game by attaching it to Python (will not be open source if I do it at all which I legally cannot confirm nor deny of such actions or intentions).~~

# How?
Sheer will and determination. I'm training this off a custom-acquired dataset I got by web-scraping captchas of a particular video game. 
I do not want to get into specifics of the video game because I do have an account with them and they can totally ban me for botting.
</br>
However, I want to be clear, this is purely for educational purposes only, I do not intend to abuse the game using the neural network. I merely want to make a proof of concept.
</br>
With that said, I can only provide a few details:
- Each image in the dataset are each 150x30
- There's a quadrilteral in the image that needs to be located
- The dataset from the game generates a unique image to serve as a captcha to prevent simple scripts that can auto-farm resources in the game. They can't stop an AI though!
- The image is a bitmap of either 1 or 0, or can be translated as such.

# What are the constraints of this silly project?
1. I allow myself Python to Webscrape and provide training data to create the dataset, remove duplicates, etc.
2. (contested) I will use libpng to parse the 150x30 image
   - Side note, this is contested because I can convert the 150x30 image into a text file of size 570 bytes.
   Remember, it's a bitmap (1 or 0) anyways! I can convert this using Python, and read this compressed format and decode it in C. Maybe libpng is not needed after all.
4. I will try to not use too many C libraries that I didn't write, only those necessary (`stdio.h`, `stdlib.h`, `math.h`, `libpng.h`[contested, see point 2])
5. Finish before October ends (Ahhhhhhhhhhhhhh)
6. NO LLMs TO WRITE THE CODE AT ALL. Using an LLM to fuzz the code or to yell at me when I write something stupid, such as a memory leak, a use after free, or general nonsense (which is like all the time), is ok, but I'm not allowed to vibe code it. All major design decisions for this project is to be done by a human. A somewhat dumb one at that, but still a human nonetheless.
