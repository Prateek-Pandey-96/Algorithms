class Solution:
    mapping = {
        0: "Zero",
        1: "One",
        2: "Two",
        3: "Three",
        4: "Four",
        5: "Five",
        6: "Six",
        7: "Seven",
        8: "Eight",
        9: "Nine",
        10: "Ten",
        11: "Eleven",
        12: "Twelve",
        13: "Thirteen",
        14: "Fourteen",
        15: "Fifteen",
        16: "Sixteen",
        17: "Seventeen",
        18: "Eighteen",
        19: "Nineteen",
        20: "Twenty",
        30: "Thirty",
        40: "Forty",
        50: "Fifty",
        60: "Sixty",
        70: "Seventy",
        80: "Eighty",
        90: "Ninety",
    }

    def process(self, num):
        str_list = []
        if num//100 != 0:
            quo = num//100
            str_list.append(self.mapping[quo] + " Hundred")
        
        if num%100 != 0:
            if num%100 in self.mapping:
                str_list.append(self.mapping[num%100])
            else:
                str_list.append(self.mapping[num%100 - (num%100)%10])
                if num%100 % 10 != 0:
                    str_list.append(self.mapping[num%100 % 10])
        return " ".join(str_list)

    def numberToWords(self, num: int) -> str:
        if num == 0:
            return "Zero"
        temp = []
        new_num = 0
        while num > 0:
            rem = num%1000
            num = num//1000
            temp.append(rem)

        # process each group
        result = []
        for i in range(len(temp)):
            part = temp[i]
            joined_part = self.process(part)
            if joined_part != "":
                if i == 1:
                    joined_part += " Thousand"
                elif i == 2:
                    joined_part += " Million"
                elif i == 3:
                    joined_part += " Billion"
                result.append(joined_part)
                
        result.reverse()
        return " ".join(result)
