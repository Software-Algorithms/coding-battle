# leetcode 5 in java

public class Solution {
    public boolean isPalindrome(String subs) {
        for(int i = 0; i<subs.length; i++) {
            if(subs[i] != subs[sub.length-i])
                return false;
        }
        return true;   
    }
    
    public String longestPalindrome(String s) {
        if( s.length==0 || s.length>1000 )
            return null;
        int maxlength = s.length;
        while(maxlength>0) {
            String subs = new String;
            for(int i=0; i<s.length-maxlength; i++){
            	subs = s.substring(i,i+maxlength);
            	if(isPalindrome) {
            		return subs;
            	}
        	}
        }
        return null;
    }
}