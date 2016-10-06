# CIS17B_Rogue_Game
RCC Fall 2016 
* Progress
  * We have come a long way since Map v1! Progress is posted to GitHub. Hector and I have just completed Map V5 without comments tho.
   So if you look through it and are confused, don't fret, i'm here to explain! So the first thing we built was a Level Builder.
   It shows the location of each room. We had to ensure that the rooms were connected and they weren't always clumped. We got that to work
   and then we had to build rooms on top of that level. so when we built rooms on the level, we saved their x and y location on the room 
   object itself so that we can compare the x and y values and retrieve the information needed.
   As for now, each room is 100% random with no organization. (this was just to fill the room and make them unique to compare result).
   If you have any questions, please ask.
   If you believe you can help us make it more efficient, please say something. We will take all ideas in to consideration
   Other than that, We can't wait to implement this in Qt and use actual pixel art
* To-Do
  - More efficient level generator
    - maybe building 3 - 4 rooms at a time
  - Create "Boss Room" -> just label it for now
  - Create room generator -> doors are important
  - Start builidng a connection where a player can move on the map

