# Cash Flow Minimizer

## 1. INTRODUCTION

The Cash Flow Minimizer tool aims to efficiently settle debts among a group of friends by minimizing the total cash flow required for transactions. It utilizes a Greedy Algorithm to determine the optimal way of distributing money among friends, resulting in minimal transactions. The first algorithm utilizes a simple approach to minimize the cash flow among friends by continually searching for the highest creditor and highest debtor. The second algorithm, however, optimizes the process using priority queues to keep track of the highest creditor and debtor.

## 2. ALGORITHMS USED:

### Original Algorithm

The original code minimizes the cash flow in a brute force manner:

1. It calculates the net payment for each friend or individual and stores the value in the payment array.
2. It searches through the entire payment array to find the friend with the maximum credit, i.e., the person who is owed the most money, and the maximum debit, i.e., the person who owes the most money.
3. It then calculates the minimum of these two amounts and simulates a transaction of this amount between the two friends.
4. The process is repeated until all debts are settled, i.e., there is no friend with a positive balance (credit) or negative balance (debit).

This approach has a time complexity of O(N^2), as it requires a full pass (O(N)) through the payment array for each transaction, and in the worst case, there could be N transactions. The space complexity is O(N) for the payment array which stores the net payment of each individual.

### Optimized Algorithm

The optimized code takes advantage of the properties of a priority queue data structure to improve efficiency:

1. It calculates the net payment for each friend and pushes it into one of two priority queues: one for friends who owe money (debit) and one for friends who are owed money (credit).
2. The priority queue automatically orders the friends by the amount of money they owe or are owed. This allows the algorithm to quickly identify the friend with the maximum debit and the friend with the maximum credit without having to scan through the entire array.
3. Similar to the original algorithm, it calculates the minimum of these two amounts and simulates a transaction of this amount between the two friends. However, instead of repeating the whole process, it simply updates the amounts in the priority queues.
4. This process is repeated until all debts are settled.

In this approach, the time complexity to minimize the cash flow and show transactions is O(N log N) as it requires a single pass (O(N)) through the payment array to calculate the net payments, after which each transaction can be performed in O(log N) time using the priority queue. But since the time complexity to calculate the net payment of each friend still requires O(N^2) time complexity, the overall time complexity of the code is O(N^2). The space complexity is O(N) for the payment array and the two priority queues.

### Advantages of the Optimization

1. Improved time efficiency: The use of priority queues in the optimized code eliminates the need for repeatedly scanning through the payment array to identify the maximum creditor and debtor. This results in faster computations.

2. More structured code: The use of priority queues and separate functions for calculating the net payments and performing the transactions makes the code in the optimized version easier to read, understand, and maintain.

## 3. FUNCTIONALITY:

The project will provide the following functionalities:

a) Efficient Debt Settlement: The project efficiently resolves debts among friends, minimizing the total cash flow required for transactions.
b) Fast Computation: The upgrade in time complexity to O(n log n) will ensure that the cash flow minimization process is performed quickly, even for large numbers of participants.
c) Scalability and Customization: The code allows for easy customization and accommodates varying numbers of participants, enabling efficient settlement of debts, even for complex cash flows.

## 4. USAGE:

**Step 1: Taking Inputs**

Begin by inputting the number of friends (n) participating in the cash flow management in the file 'cashFlow.txt'. Ensure that n is a positive integer representing the total number of individuals involved in the financial transactions. Create an n x n matrix to represent the cash flow among the friends. The matrix should reflect the amount each person owes or is owed by others within the group. The matrix elements will be of the form matrix[i][j], indicating the amount the i-th person owes to the j-th person.

**Step 2: Understanding the Cash Matrix**

The diagonal elements of the matrix (matrix[i][i]) should be zero since an individual does not owe anything to themselves. The total credit amount of the i-th person is calculated by adding the values of the matrix in the i-th column, and the total debit amount of the i-th person is calculated by adding the values of the matrix in the i-th row.

**Step 3: Run the Cash Flow Minimizer**

Once the number of friends and the cash matrix are input, execute the Cash Flow Minimizer using a C++ compiler to optimize the cash flow and identify the most efficient transactions to settle debts.