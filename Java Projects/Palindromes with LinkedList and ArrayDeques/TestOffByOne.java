import org.junit.Test;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

public class TestOffByOne {

    // You must use this CharacterComparator and not instantiate
    // new ones, or the autograder might be upset.
    static CharacterComparator offByOne = new OffByOne();
    static Palindrome palindrome = new Palindrome();

    @Test
    public void testequalChars() {


        assertTrue(offByOne.equalChars('a', 'b'));
        assertTrue(offByOne.equalChars('r', 'q'));
        assertTrue(offByOne.equalChars('b', 'a'));
        assertTrue(offByOne.equalChars('B', 'A'));
        assertTrue(offByOne.equalChars('*', '+'));
        assertTrue(offByOne.equalChars('@', 'A'));
        assertFalse(offByOne.equalChars('Z', 'a'));
        assertFalse(offByOne.equalChars('c', 'a'));
        assertFalse(offByOne.equalChars('a', 'e'));
        assertFalse(offByOne.equalChars('z', 'a'));
        assertFalse(offByOne.equalChars('a', 'a'));
        assertFalse(offByOne.equalChars('A', 'a'));
        assertFalse(offByOne.equalChars('b', 'Z'));
        assertFalse(offByOne.equalChars('@', '!'));
        assertFalse(offByOne.equalChars('@', 'a'));
        assertFalse(offByOne.equalChars('A', '#'));

        
        assertTrue(palindrome.isPalindrome("flake", offByOne));
        assertTrue(palindrome.isPalindrome("BBCA", offByOne));
        assertTrue(palindrome.isPalindrome("sonr", offByOne));
        assertFalse(palindrome.isPalindrome("aba", offByOne));
        assertFalse(palindrome.isPalindrome("Baba", offByOne));
    }
}
