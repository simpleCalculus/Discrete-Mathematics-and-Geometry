import java.util.LinkedList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n;
        n = in.nextInt();
        int P = 1;
        int sq = (int)Math.sqrt(2 * n);
        for (int i = 2; i <= sq; ++i) {
            if (2 * n % i == 0) {
                int k = 2 * n / i;
                if (k < i + 1 && (2 * n / k - k + 1) % 2 == 0) {
                    P = Math.max(P, k);
                }
                if (i < k + 1 && (2 * n / i - i + 1) % 2 == 0) {
                    P = Math.max(P, i);
                }
            }
        }
        int A = (2 * n / P - P + 1) / 2;
        System.out.println(A + " " + P);
    }
}
