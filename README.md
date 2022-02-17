## Module 1 - Generative Art: Milk and Honey

[Video Demonstration](https://youtu.be/yvsUrM1Z54Y)

### Vision
This project was a use of the TTGO T-Display module with an ESP32 chip to display a poem to be displayed in an elevator lobby at Barnard College. Since the screen is relatively small than the smartphones that we are used to, I decided to go with a poem from Milk and Honey by Rupi Kaur. I thought that the minimalist aesthetic with small, short poems fit nicely with the small form factor that we were to show our poems on. I also chose the poem on page 1 about milk and honey for the same reasons.

### General Idea
I wanted to make a codebase for which any poem, properly processed, would be compatible for display with the codebase that I am running. In theory, someone could send me a poem, and without any extra processing, my code would display it. Therefore, I designed the code in a way where the list of words are listed in a string array and the code iterates through this array and does its processing at each word. This array will include things such as "_line" and "_stanza" to create a new line clear the screen respectively.

Another concept I wanted to excecute is the idea of showing the words at a speed close to how a person would it out loud. Therefore, each word is displayed at varying intervals, based on how many letters the word had.

### Setup: Software
The software was done within the Arduino IDE. Using the Free_Fonts.h library, the idea is to iterate over the poem array and display each word for a time based on 100 milliseconds * how many letters it has. This turns out to be a pretty good approximation for how long it takes to read a word. Special command words, such as "_italic" and "_line" change the style and display method of the following words. The code is attached in [this repo](https://github.com/akihigaki/akihigaki.github.io)

### Setup: Hardware
The hardware setup is pretty simple. A TTGO T-Display is placed within a paper envelope and secured with double-sided tape. A small 3.7V lipo battery is also put in this envelope, plugged into the TTGO T-Display, and also secured with tape. The envelope is then suspended through a hole using a piece of black thread and a popsicle stick. I also decorated the envelope with a bee and some honey, like in the book.

Picture of setup.

### Technical Issues
One of the biggest issues in this project came with the setup, where I was not able to get the code uploaded and working in the examples. After a few tries and changes of the driver, I was able to get it to work. Pay special attention to the setup documentation when using this device. In addition, it is somewhat difficult to use the fonts in this libary, so reading the documentation within the comments of the code is also very helpful.

Hope you liked this project!
