import java.util.Scanner;
public class Solution {
	public static void main(String[] args) {	
            boolean found;
            int i,k,icnt=0,n=5,inp,j,count=2;
            long fcnt=1;
            final int BMOD = 1000007;
            Scanner scan = new Scanner(System.in);
            inp = scan.nextInt();
            if (inp==1 || inp==2){
                System.out.println(inp);
                System.exit(0);
            }
            int[] primes= new int[inp];
            primes[0] = 2;
            primes[1] = 3;
            while ( n <= inp ) {
                i = 1;
		found = true;
		k = n/2;                
		while ( primes[i] <= k ) {
                    if ( (n % primes[i++]) == 0 ) {  
                        found = false; 
                        break;
                    }
                }
                if ( found ) {
                    primes[count] = n;
                    ++count;
                }
                n += 2; 
            }
            k = inp/2;
            for(i=0;primes[i]<=k;i++)
            {
		j=inp;
                icnt=0;
                while(j>=primes[i]) { 
                    j = j/primes[i];
                    icnt = icnt + j;
                }
                fcnt = fcnt * ((2*icnt)+1);
		if(fcnt>BMOD) fcnt = fcnt%BMOD; 
            }
            icnt = count-i;
            while(icnt!=0)
            {
		fcnt = fcnt * 3;
		if(fcnt>BMOD) fcnt = fcnt%BMOD;
		icnt--;
            }
            System.out.println(fcnt);
	}
} 