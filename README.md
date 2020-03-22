# Pinball Game
# Introduction
Pinball is a very famous game; even before computers! It used to be a purely mechanical game with a lot of effort put in it (till this very day!). With the rise of computers and video games, awhole family of Pinball video games were developed. There are plenty of free online web-based Pinball games you may try to get familiar with the game before continuing to read the document; e.g., Pinball: Space Adventure .
# Project Scope
The project is a simplified 2D game with minimal graphics, e.g., the first round lane of motion with the spring is not required. Any advanced aesthetic looks are not required but will be rewarded with bonus marks. Only two control buttons are required (in addition to the exit action). The motion simulation is done by dividing time into small frames and applying the classical equations of motion for one particle under uniform acceleration (see here ) during these frames. No advanced dynamics background is needed.
# Components
Following are the definitions of the components we will be using in our Pinball game project!
# Ball
A metallic ball bouncing around hitting various objects. The game is over when the ball is down the drain (outside the bottom limit of the game in video games).
# Flippers
Two controllable levers that can kick the ball back up whenever encountered. The speed and direction of the kick differ depending on the speed and position of both the flipper and the ball when kicked.
# Obstacles
Obstacles are what we are going to call everything else that the ball can collide with. Each collision may have an effect on the ball and increase/decrease the score by some factor.
(1) Wall & Ceiling.
(2)Bumpers : 
Pop bumpers, Thrust bumpers, Vibranium bumpers.
(3) Kickers/Slingshots
(4) Rollovers :
Speed boosters, Collectables.
(5) Targets :
Score multipliers, Bullseye [Bonus].
(6) Routers :
Switches, Gates, Ramps [Bonus], Lanes [Bonus], Portals [Bonus].
(7) Extras :
Magnets [Bonus], Captives [Bonus Advanced].
# Phase 1 Requirements
Reading the layout configuration from a file: Includes the obstacles and initial position and velocity of the ball.
Reading user input and control the flippers.
Drawing all components as well as the live score in the corner of the screen.
Detecting “Game Over” and displaying the final score.
# Phase 2
Detecting collisions between the ball and the different kinds of obstacles.
Using the physical properties of the different obstacles to change the ball’s course of motion.
# Grading Criteria
Non-working code will be penalized by 50% of the grade (per requirement).
Failing to adhere to OOP concepts will be penalized 40% of the grade (per requirement).
Memory leaks will be penalized by 10% of the grade (per requirement).
Any sign of plagiarism will be punished by 100% of the grade.
