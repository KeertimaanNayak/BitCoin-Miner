# Summer_of_Bitcoin2021
Summer of Bitcoin code challenge 2021- Maximizing profit to a Bitcoin Miner


# Motivation behind the project:

My motivation behind this project was to apply my knowledge and solve a real life problem. This project was asked in the Summer of Bitcoin 2021 challenge and the problem statement was to select optimal transactions producing maximum profit to a bitcoin miner.  


# Project Explanation:
This project is based on a real life problem faced by a bitcoin miner. So, the work of a Bitcoin miner is to construct blocks by selecting a set of transactions from their mempool. Now each transaction in the mempool has got a certain fee which is collected by the miner if the transaction gets included in the block.
Also, each transaction has a weight which indicates the size of transactions. And also, it may be possible that a transaction contains two or more parent transactions which means that before taking a particular transaction, it is a must to take all its parent transactions. 

Now, the job of a miner is to select an ordered list of transactions which have a combined weight below the maximum block weight and which also satisfies the parent child constraint. 
Now, naturally every miner wants to maximize its total fee.

So, here my work was to analyze the transactions and come up with an ordered list of transactions which satisfies the constraints and provides maximum profit to the miner.
 
 
# Challenges faced:

This was a heuristic problem and was aimed at optimizing more and more to reach as close as possible to the perfect answer. 
However a 100% perfect answer to the problem can be found out using min cut max flow algorithm. 
However, considering the time complexity of min cut max flow algorithm, it can not be applied to large data sets having transaction ids close to 5000. Hence this was challenging to reach close to a perfect answer without using min cut max flow algorithm. 


# Further Improvement: 

I am planning to understand and learn the min cut max flow algorithm and further pruning the cases to optimize the time and come up with an even better answer.


# How does my algorithm work?

Firstly, I was given a CSV file and I extracted the information using File handling and then applied two algorithms to optimize the result.

Initially I started with a Bit Masking technique to iterate over all possible combinations and find the maximum profit to a miner satisfying the constraints. However, it can only be used on a small dataset containing close to 15 transaction ids.

Then to work on a large dataset I applied a knapsack algorithm for implementation of a greedy based technique starting with sorting the transactions in the order of fee/weight  and further implementing a heap based structure for checking the existence of parents in the block. 

# Results of Bit Masking technique:
Transaction count: 15
Total fees in current block: 3,548
Total Weight: 11,952
Transactions in final block: 9

# Results of Knapsack technique:
Transaction count: 5,214
Total fees in current block: 56,96,031
Total Weight: 39,99,936
Transactions in final block: 3,174
