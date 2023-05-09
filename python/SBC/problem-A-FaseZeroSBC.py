# beecrowd | A
# Algorithm Tests

# Por Neilor Tonin, SBC - Sociedade Brasileira de Computação

# Brazil
# Timelimit: 1
# Lately, Professor Adrien Sinando has been kinder than usual and, for his Algorithms class, he wants to grade the students as follows: 
# there will be two mandatory tests, test 1 and test 2 (p1 and p2), and for those who does only the tests, the final score will be given by 
# the simple arithmetic average of the scores of the two tests. Whoever does an extra assignment will have the third score as an additional one, 
# and then the final score will be the average of the three score, all with the same weight. If the student thinks that any of these 3 scores was low, 
# he can still take a substitute test for the lowest grade (provided that he has done the assignment). Obviously, if the substitute test score is the lowest, 
# Professor Adrien will ignore it. If any student makes only one assessment, it will be considered 0 (zero) for their second score.
# Now, Professor Adrien wants you to make a system to help him calculate the averages, 
# since the class is large and the calculation of averages has some particularities.

# Input
# The first input line contains an integer N (1 < N < 60) that represents the number of students in the class. 
# Then, N pairs of lines follow (i.e. a total of 2N lines). The first line of each pair contains the name of a student, 
# and the second line contains the scores of that student, possibly one, two, three, or four scores, 
# all given in the range {0, …, 10} with one place after the decimal point, as described above. The name of no student has more than 20 characters.

# Output
# For each student, your program must present the student's name followed by a colon ':', a space and the average of this student with one digit after the decimal point, 
# according to the example below.

# Samples Input	Samples Output

# 4
# Joao Souza
# 8.3 7.8
# Pedro Silva
# 1.0
# Maria Revate
# 6.1 8.2 7.1 9.4
# Sonia Campos
# 6.2 3.1 9.4
	

# Joao Souza: 8.1
# Pedro Silva: 0.5
# Maria Revate: 8.2
# Sonia Campos: 6.2

# 3
# Ava Ricela
# 6.1 8.2 7.1 9.4
# Paulo Rotas
# 9.1 6.2 3.1 9.4
# Gersom Atorio
# 9.0 5.0 7.3 2.0


# Ava Ricela: 8.2
# Paulo Rotas: 8.2
# Gersom Atorio: 7.1"""

def average(array):
    return sum(array)/len(array)

def main():
    N = int(input())
    
    for i in range(N):
        name = input()
        scores = [float(x) for x in input().split()]

        if len(scores) == 1:
            score = scores[0]/2
            print(name+':', f'{score:.1f}' )
        elif len(scores) >= 4:
            scores.sort(reverse=True)
            print(name+':', f'{average(scores[:3]):.1f}' )
        else:
            print(name+':', f'{average(scores):.1f}' )
        
if __name__ == '__main__':
    main()