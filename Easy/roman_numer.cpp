class Solution {
public:
    int romanToInt(string s) {
        // I = 1, V = 5, X = 10, L = 50, C = 100, D = 500, M = 1,000
        // lower letters work ?
        // In this system, a letter placed after another of greater value adds (thus XVI or xvi is 16),
        // whereas a letter placed before another of greater value subtracts (thus XC or xc is 90).
        int sum = 0;
        int len = s.size();
        
        char ch[100] = {};
        
        for(int i = 0; i<len; i++) {
            ltter = s(i);
            switch (letter) {
                case 'M':
                case 'm':
                    val =1000;
                break;
                
                case 'D':
                case 'd':
                    val +=500;
                break;
                
                case 'C':
                case 'c':
                    val +=100;
                break;
                
                case 'L':
                case 'l':
                    val +=50;
                break;
                
                case 'X':
                case 'x':
                    val +=10;
                break;
                
                case 'V':
                case 'v':
                    val +=5;
                break;
                
                case 'I':
                case 'i':
                    val +=1;
                break;
        }
        }
        

        
    }
};