import org.junit.Test;

import static org.junit.Assert.*;

public class TestPalindrome {
    // You must use this palindrome, and not instantiate
    // new Palindromes, or the autograder might be upset.
    static Palindrome palindrome = new Palindrome();

    @Test
    public void testWordToDeque() {
        Deque d = palindrome.wordToDeque("persiflage");
        String actual = "";
        for (int i = 0; i < "persiflage".length(); i++) {
            actual += d.removeFirst();
        }
        assertEquals("persiflage", actual);
    }

    @Test
    public void isPalindrome() {
        assertFalse(palindrome.isPalindrome("cat"));
        assertTrue(palindrome.isPalindrome("sugus"));
        assertTrue(palindrome.isPalindrome("a"));
        OffByOne off = new OffByOne();
        assertTrue(palindrome.isPalindrome("flake", off));
        assertTrue(palindrome.isPalindrome("sonr", off));
        assertFalse(palindrome.isPalindrome("aba", off));
        OffByN ofn = new OffByN(2);
        assertTrue(palindrome.isPalindrome("adfc", ofn));
        assertTrue(palindrome.isPalindrome("adc", ofn));
        assertFalse(palindrome.isPalindrome("aefc", ofn));
    }

}
