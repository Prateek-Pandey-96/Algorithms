# 2038. Remove Colored Pieces if Both Neighbors are the Same Color
class Solution:
    def winnerOfGame(self, colors: str) -> bool:
        # base case
        n = len(colors)
        if n<3:
            return False
        
        alice_count, bob_count = 0, 0

        char = colors[0]
        count = 1
        
        for i in range(1, n):
            if colors[i]==char:
                count += 1
            else:
                if count >= 3:
                    if char == 'A':
                        alice_count += count-2
                    else:
                        bob_count += count-2
                char = colors[i]
                count = 1
        # handle last sequence
        if count >= 3:       
            if char == 'A':
                alice_count +=  count-2
            else:
                bob_count +=  count-2
        
        return alice_count > bob_count