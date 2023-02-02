# Lab 2
[Fork](https://docs.github.com/en/get-started/quickstart/fork-a-repo) this repo and clone it to your machine to get started!

## Team Members
- Ian Gravallese


## Lab Question Answers

Question 1: How did the reliability of UDP change when you added 50% loss to your local
environment? Why did this occur?

Answer for Question 1: 
Only around %50 of the messages were sent (actually, it was 4/10), so the reliability of the connection was affected essentially 1:1 with the imposed loss.


Question 2: How did the reliability of TCP change? Why did this occur?

Answer for Question 2: 
The reliability of TCP did not change; all meesages were delivered.


Question 3: How did the speed of the TCP response change? Why might this happen?

Answer for Question 3: 
The speed of the TCP response was slower with the imposed %50 loss. This is likely because the network has to work to establish which packets were lost (not delivered) and to retreive/retransmit them.
