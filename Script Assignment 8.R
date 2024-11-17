#1. Can you spot the difference between a character string and a number? Here’s a test: Which of these are character strings, and which are numbers? 1, "1", "one".

is.character(1)        #returns FALSE, 1 is numeric
is.character("1")      #returns TRUE, "1" is character
is.character("one")    #returns TRUE, "one" is character

#2. Create an atomic vector that stores just the face names of the cards in a royal flush, for example, the ace of spades, king of spades, queen of spades, jack of spades, and ten of spades. The face name of the ace of spades would be “ace,” and “spades” is the suit.

face_names <- c("ace", "king", "queen", "jack", "ten")

#2a. Which type of vector will you use to save the names?

# A character vector is used to save the face names of the cards.

#3. Create the following matrix, which stores the name and suit of every card in a royal flush.
## [,1] [,2] ## [1,] "ace" "spades" ## [2,] "king" "spades" ## [3,] "queen" "spades" ## [4,] "jack" "spades" ## [5,] "ten" "spades"

royal_flush <- matrix(c("ace", "spades", 
                        "king", "spades", 
                        "queen", "spades", 
                        "jack", "spades", 
                        "ten", "spades"), 
                      nrow = 5, byrow = TRUE)

royal_flush

#4. Many card games assign a numerical value to each card. For example, in blackjack, each face card is worth 10 points, each number card is worth between 2 and 10 points, and each ace is worth 1 or 11 points, depending on the final score.
# Make a virtual playing card by combining “ace,” “heart,” and one into a vector.

virtual_card <- c("ace", "heart", "1")

typeof(virtual_card)

#4a. What type of atomic vector will result?
# The vector will be a character vector.

#5. Use a list to store a single playing card, like the ace of hearts, with a point value of one. The list should save the face of the card, the suit, and the point value in separate elements.

single_card <- list(
  face = "ace",
  suit = "hearts",
  points = 1
)

single_card