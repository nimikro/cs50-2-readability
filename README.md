# cs50-2-readability - Summary
This is a command line application developed in C# that computes the approximate grade level needed to comprehend some input text. This is an exercise of Harvard's CS50 online course.

# Table of contents
1. [Readability](#Readability)
2. [Reading Levels](#Reading-Levels)
3. [Specification](#Specification)

# Readability
This program computes the approximate grade level needed to comprehend some text, per the below.
```
$ ./readability
Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
Grade 3
```

# Reading Levels
According to Scholastic, E.B. White’s “Charlotte’s Web” is between a second and fourth grade reading level, and Lois Lowry’s “The Giver” is between an eighth grade reading level and a twelfth grade reading level. What does it mean, though, for a book to be at a “fourth grade reading level”?

Well, in many cases, a human expert might read a book and make a decision on the grade for which they think the book is most appropriate. But you could also imagine an algorithm attempting to figure out what the reading level of a text is.

So what sorts of traits are characteristic of higher reading levels? Well, longer words probably correlate with higher reading levels. Likewise, longer sentences probably correlate with higher reading levels, too. A number of “readability tests” have been developed over the years, to give a formulaic process for computing the reading level of a text.

One such readability test is the Coleman-Liau index. The Coleman-Liau index of a text is designed to output what (U.S.) grade level is needed to understand the text. The formula is:
```
index = 0.0588 * L - 0.296 * S - 15.8
```
Here, L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.

This program called readability takes a text and determines its reading level. For example, if user types in a line from Dr. Seuss:
```
$ ./readability
Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
Grade 3
```
The text the user inputted has 65 letters, 4 sentences, and 14 words. 65 letters per 14 words is an average of about 464.29 letters per 100 words. And 4 sentences per 14 words is an average of about 28.57 sentences per 100 words. Plugged into the Coleman-Liau formula, and rounded to the nearest whole number, we get an answer of 3: so this passage is at a third grade reading level.

Let’s try another one:
```
$ ./readability
Text: Harry Potter was a highly unusual boy in many ways. For one thing, he hated the summer holidays more than any other time of year. For another, he really wanted to do his homework, but was forced to do it in secret, in the dead of the night. And he also happened to be a wizard.
Grade 5
```
This text has 214 letters, 4 sentences, and 56 words. That comes out to about 382.14 letters per 100 words, and 7.14 sentences per 100 words. Plugged into the Coleman-Liau formula, we get a fifth grade reading level.

As the average number of letters and words per sentence increases, the Coleman-Liau index gives the text a higher reading level. If you were to take this paragraph, for instance, which has longer words and sentences than either of the prior two examples, the formula would give the text an eleventh grade reading level.
```
$ ./readability
Text: As the average number of letters and words per sentence increases, the Coleman-Liau index gives the text a higher reading level. If you were to take this paragraph, for instance, which has longer words and sentences than either of the prior two examples, the formula would give the text an eleventh grade reading level.
Grade 11
```

# Specification
Implemented a program, readability, that computes the Coleman-Liau index of the text, according to the following.

* The program prompts the user for a string of text (using get_string).
* The program counts the number of letters, words, and sentences in the text. We assume that a letter is any lowercase character from a to z or any uppercase character from A to Z, any sequence of characters separated by spaces counts as a word, and that any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.
* The program prints as output "Grade X" where X is the grade level computed by the Coleman-Liau formula, rounded to the nearest integer.
* If the resulting index number is 16 or higher (equivalent to or greater than a senior undergraduate reading level), the program outputs "Grade 16+" instead of giving the exact index number. If the index number is less than 1, the program outputs "Before Grade 1".
