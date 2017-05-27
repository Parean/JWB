/*
	Number of comment lines 18
	SLOC 48
	CP 0.375
*/
package graphics;

/** 6
 *  7
 *  8
 *  9
    10  */

import java.util.Date;
import java.io.*;

enum Direction
{
	// 11
   UP
   { // 12
        public Direction opposite() { return DOWN; }
   },
   DOWN
   {
        public Direction opposite() { return UP; }
   };

   public abstract Direction opposite();
}

// Only names counted
@History({
        @Version(
                version = 1,
                date = @Date(year = 2001, month = 1, day = 1)),
        @Version(
                version = 2,
                date = @Date(year = 2002, month = 2, day = 2),
                authors = {@Author(value = "Jim Smith", title = JUNIOR)},
                previous = MyClassVer1.class),
        @Version(
                version = 3,
                date = @Date(year = 2003, month = 3, day = 3),
                authors = {
                        @Author(value = "Jim Smith", title = MIDDLE),
                        @Author(value = "Anna Lea")},
                previous = MyClassVer2.class)
})


public class BinaryConverter {

    public static void main(String[] args){
        for(int i = -5; i < 33; i++){
            System.out.println(i + ": " + toBinary(i));
            System.out.println(i);

            System.out.println(i + ": " + Integer.toBinaryString(i));
        }
    }

    // 14
    public static String toBinary(int base10Num){
        boolean isNeg = base10Num < 0;
        base10Num = Math.abs(base10Num);
        String result = "";

        while(base10Num > 1){
            result = (base10Num % 2) + result;
            base10Num /= 2;
        }
        assert base10Num == 0 || base10Num == 1 : "value is not <= 1: " + base10Num;

        result = base10Num + result;
        assert all0sAnd1s(result);

        if( isNeg )
            result = "-" + result;
        return result;
    }

    /* 15
     * 16
     * 17
       18 */
    public static boolean all0sAnd1s(String val){
        assert val != null : "Failed precondition all0sAnd1s. parameter cannot be null";
        boolean all = true;
        int i = 0;
        char c;

        while(all && i < val.length()){
            c = val.charAt(i);
            all = c == '0' || c == '1';
            i++;
        }
        return all;
    }
}
