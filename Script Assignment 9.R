# 1. Matrix Setup: Create an n x 3 matrix with slot symbols
set.seed(123)
symbols <- c("diamond", "heart", "club")
n <- 10  #number of rows
slot_matrix <- matrix(sample(symbols, n * 3, replace = TRUE), nrow = n, ncol = 3)

print("Slot Matrix:")
print(slot_matrix)

# 2. Define Scoring Rules
# A scoring function that awards points based on matching symbols in a row:
# 3 matching symbols: 10 points
# 2 matching symbols (without wilds): 5 points
# Diamonds as wild can substitute any symbol to make a match.

# 3. Vectorized Scoring Function
score_slots <- function(slot_matrix, diamond_wild = TRUE) {
  apply(slot_matrix, 1, function(row) {
    
    #check if all symbols match
    if (diamond_wild) {
      
      #diamonds are wild: replace them with the first non-diamond symbol (if any)
      main_symbol <- row[row != "diamond"]
      main_symbol <- ifelse(length(main_symbol) > 0, main_symbol[1], "diamond")
      match_count <- sum(row == main_symbol | row == "diamond")
    } else {
      
      #regular scoring without wilds
      main_symbol <- row[1]
      match_count <- sum(row == main_symbol)
    }
    
    #scoring based on the count of matches
    if (match_count == 3) {
      return(10)
    } else if (match_count == 2) {
      return(5)
    } else {
      return(0)
    }
  })
}

# 4. Test Both Versions

#test with diamonds as wild
scores_with_wild <- score_slots(slot_matrix, diamond_wild = TRUE)

cat("\nScores with diamonds as wild:\n")
print(scores_with_wild)

#test without diamonds as wild
scores_without_wild <- score_slots(slot_matrix, diamond_wild = FALSE)

cat("\nScores without diamonds as wild:\n")
print(scores_without_wild)

# 5. Reflection
cat("\nReflection:\n")
cat("Using vectorized functions (like apply) makes scoring more efficient, especially when scaling larger matrices.\n")
cat("With diamonds as wild, more rows score points as diamonds can substitute any symbol. Without wilds, the scores are generally lower.\n")

# 5 (Continued)
#load library
#microbenchmark runs each scoring version (with and without wilds) 1,000 times and records the time taken
if (!require(microbenchmark)) install.packages("microbenchmark")
library(microbenchmark)

#compare performance of vectorized scoring with and without diamonds as wild
benchmark_results <- microbenchmark(
  with_wild = score_slots(slot_matrix, diamond_wild = TRUE),
  without_wild = score_slots(slot_matrix, diamond_wild = FALSE),
  times = 1000  # Number of repetitions to get an accurate average
)

# results
print(benchmark_results)

#summary statistics to compare mean execution times
summary(benchmark_results)
