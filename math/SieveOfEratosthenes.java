
class SieveOfErathostenes {

    private boolean[] isPrime;

    public SieveOfErathostenes(int n) {
        isPrime = new boolean[n + 1];
        Arrays.fill(isPrime, true);
        fill();
    }

    public isPrime(int i) {
        if (i < 0 || i >= isPrime.length()) {
            throw IllegalArgumentException(String.format("The range for this sieve is [0, %d]", isPrime.length() - 1));
        }

        return isPrime[i];
    }

    private fill() {
        int n = isPrime.length() - 1;
        for (int i = 2; i * i <= n; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }
}