# Qt-Game-Development

# Game 1: Battleship Game

![image](https://user-images.githubusercontent.com/60234076/167738227-6a303a4f-d0db-413c-968a-8999c980d541.png)

Description: The goal is to find and strike the battleships presenting bad coding practices by answering questions about software development. The artwork teaches best practices in software development
such as documenting code, using version control, testing, debugging, etc.. On the other hand, a student
skipping the unit testing part with a consequence of suffering with a buggy very long code is considered
a bad practice in programming.

User is prompted with questions

If answered correctly You gain a point

7 out of 10 correct -> wins game

4 incorrect -> loses game

If 16 attempts reach 0 then if 

Correct > wrong --> user wins, otherwise

![image](https://user-images.githubusercontent.com/60234076/167737645-fd46321e-09b0-4daa-9ef4-3862879ed506.png)


• Game overview:

– The game is played on 2 4x4 gridded board.

– The player starts after clicking the play button or pressing F1.

– The user clicks on coding bad practices cells to find the ships. If a ship is under the chosen box, the player answers the question correctly to hit the ship.

– If the question is answered correctly, the enemy ship (bad coding practices) is hit.

– If the answer is incorrect, your shot is missed and your enemy fires back, hitting one of your ships. The enemy’s hit can be randomly set at any location.

– If no question is found in the box, the trial is missed and the total number of attempts is reduced by 1. The cell is hence marked by any color or shape as per the below figure.

– The player can have up to 16 trials to uncover all the cells - all trials must be consumed.

– The player wins if 7 out of 10 questions are answered correctly.

– The player fails if 4 questions are answered incorrectly.

– At least one ship must span up to 3 cells. Others can fit in 1 cell.

– Questions and answers should be saved and read from a txt/json file.

– Game can be customized to reflect other areas. That is the user can at any time change all the questions and the corresponding answers according to the new topic.

• Valid Hits:

– Inside the boxes of the right grid.

• Game Ends:

– When the total number of trials is 0.


# Game 2: Shooting Discs Game

![image](https://user-images.githubusercontent.com/60234076/167738306-b8b51695-d31f-470e-a0f0-4bc6f9666c2b.png)

Description: ShootingH is a classic shooting game. Shoot as much as you can and hit the objects.
The original game involves arbitrary shooting with a counter. The winner is the first player to reach
the target. We will introduce some changes to tweak the objective of the game and add an algorithmic
purpose.

Discs fall from the top where the user presses:

Left key -> red; Down key -> green; Right key -> Blue;

The user should get as discs many as they can

Red discs are worth 3 points, green are 5, blue are 7

Every 30 points, the game becomes faster and harder by spawning more discs

![image](https://user-images.githubusercontent.com/60234076/167737821-5c6898e4-bf39-42c7-b0eb-1d98ab992db4.png)

Detailed Description and Rules:

• The game is played on a rectangular grid board.

• A number of discs is placed randomly on a scrolling board. When the disc is hit, it turns into a grey disc and the counter is increased. Otherwise, it disappears.

• The objective of the game is to hit high number of discs.

• There are 3 types of discs: red, green and blue. Each disc type is represented by a distinctly colored game piece token.

• There are 3 counters for the different types of viruses and a total score. Red discs are worth 3 points; Green discs are worth 5 points; Blue discs are worth 7 points.

• The player starts after clicking the play button or pressing F1. The player collects points when he successfully hits the target. The score is incremented according to the type of the disc being hit.

• To win the game, the player must collect 150 points regardless of the counter. If the total score is more than a 150, the player wins and the additional points are considered as a bonus and saved separately.

• The rolling speed starts slowly. The speed is doubled after collecting 30 points. For instance, if the starting speed is 1x, the speed becomes 2x after the first 30 points, then 4x after 60 points and o on. The speed should not exceed 16x (which occurs at 120 points).

• The player looses if he misses hitting 3 discs.

