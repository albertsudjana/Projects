import org.junit.Test;

import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

public class TestOffByN {

    // You must use this CharacterComparator and not instantiate
    // new ones, or the autograder might be upset.
    static CharacterComparator offByOne = new OffByOne();

    @Test
    public void testequalChars() {
        OffByN obo = new OffByN(5);

        assertTrue(obo.equalChars('a', 'f'));
        assertTrue(obo.equalChars('f', 'a'));
        assertFalse(obo.equalChars('f', 'h'));
    }
}
