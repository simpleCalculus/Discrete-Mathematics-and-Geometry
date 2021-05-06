import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n, k;
        n = in.nextInt();
        k = in.nextInt();
        if (n == 2) {
            System.out.println(k * (k - 1));
            System.exit(0);
        }
        int[] dp = new int[n];
        int[] zero = new int[n];
        zero[0] = 1;
        zero[1] = k - 1;
        dp[0] = k;
        dp[1] = k*k - 1;
        for (int i = 2; i < n; ++i) {
            if (i == n - 1) {
                dp[i] = dp[i - 1] * (k - 1);
            } else {
                dp[i] = dp[i - 1] * k - zero[i - 1];
                zero[i] = dp[i - 1] - zero[i - 1];
            }
        }
        System.out.println(dp[n - 1]);
    }
}
