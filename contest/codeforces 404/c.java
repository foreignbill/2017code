import java.math.*;
import java.util.*;

public class Main{
	
	public static void main(String [ ] arguments){
		Scanner cin = new Scanner(System.in);
		BigInteger n,m;
		n=cin.nextBigInteger();
		m=cin.nextBigInteger();
		BigInteger tmp = m.add(BigInteger.valueOf(-1).multiply(n));
		BigInteger Square=BigInteger.ONE.add(BigInteger.valueOf(-8).multiply(tmp));
		BigInteger L,R,ans=BigInteger.valueOf(0);
		L=BigInteger.ONE;R=Square;
		while(L.compareTo(R)<=0){
			BigInteger Mid=L.add(R);
			Mid=Mid.divide(BigInteger.valueOf(2));
			BigInteger t = Mid.multiply(Mid);
			if(t.compareTo(Square)<=0){
				ans = Mid;
				L = Mid.add(BigInteger.ONE);
			} else {
				R = Mid.add(BigInteger.valueOf(-1));
			}
		}
		BigInteger tt=ans.multiply(ans);
		ans = ans.add(BigInteger.valueOf(-3));
		ans = ans.divide(BigInteger.valueOf(2));
		if(tt.compareTo(Square)<0){
			ans=ans.add(BigInteger.ONE);
		}
		ans = ans.add(BigInteger.ONE);
		if(n.compareTo(m)>=0)System.out.println(ans.add(m));
		else System.out.println(n);
	}
}