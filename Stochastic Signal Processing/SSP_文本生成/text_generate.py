import random
import re

# Prepare training data
text = "Forget that there are places in the world that aren't made out of stone.There's something inside that they can't get you that they can't touch.That's yours."
# Convert the text to lowercase and split it into a list of words and punctuation marks
words = re.findall(r"[\w']+|[.,!?;]", text.lower())

# Build transition matrix
transition_matrix = {}

# Calculate the frequency of each word followed by the next word
for i in range(len(words) - 1):
    current_word = words[i]
    next_word = words[i + 1]
    if current_word in transition_matrix:
        if next_word in transition_matrix[current_word]:
            transition_matrix[current_word][next_word] += 1
        else:
            transition_matrix[current_word][next_word] = 1
    else:
        transition_matrix[current_word] = {next_word: 1}

print(transition_matrix)

# Adjust the weight of punctuation marks
punctuations = set([',', '.', '!', '?'])
for p in punctuations:
    if p in transition_matrix:
        for next_word in transition_matrix[p]:
            transition_matrix[p][next_word] *= 3

# Convert frequencies to probabilities
for current_word in transition_matrix:
    total = sum(transition_matrix[current_word].values())
    for next_word in transition_matrix[current_word]:
        transition_matrix[current_word][next_word] /= total

# Update the function to generate random text
def generate_text(transition_matrix, start_word, length):
    current_word = start_word
    generated_text = [current_word]
    for _ in range(length - 1):
        # Try to get the next word
        if current_word in transition_matrix and len(transition_matrix[current_word]) > 0:
            next_words = list(transition_matrix[current_word].keys())
            probabilities = list(transition_matrix[current_word].values())
            next_word = random.choices(next_words, weights=probabilities)[0]
        else:
            # If the current word has no following word, choose a new starting word
            current_word = random.choice(list(transition_matrix.keys()))
            continue
        generated_text.append(next_word)
        current_word = next_word
    return ' '.join(generated_text)

# Choose a starting word, here we choose the most common word in the text as the starting word
start_word = max(transition_matrix.keys(), key=lambda k: sum(transition_matrix[k].values()))

# Generate random text of 100 words
generated_100_words = generate_text(transition_matrix, start_word, 100)
print(generated_100_words)
