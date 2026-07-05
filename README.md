# pingy pongy
> With the amazing help of GLUT.
###### How the heck do I make pong using OpenGL?
OKAY, from what I've gathered, GLUT is a toolkit for OpenGL that abstracts a lot of the complicated operations we'll be doing to generate, display, and refresh our pong game.
An interesting thing I learned about GLUT's workflow is callback functions, which we the user implement!
+ glutDisplayFunc( display );
+ glutReshapeFunc( reshape );
+ glutTimerFunc(0 (ms delay), timer, 0);
