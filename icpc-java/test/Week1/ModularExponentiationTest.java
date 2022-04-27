package Week1;

import org.junit.Test;
import static Week1.ModularExponentiation.*;


import static org.junit.Assert.*;

public class ModularExponentiationTest {

    @Test
    public void main() {
        assertEquals(6, modExpIterative(2, 5, 13));
        assertEquals(6, modExpRecursive(2, 5, 13));
        assertEquals(3, modExpRecursive(3, 1, 4));
        assertEquals(3, modExpIterative(3, 1, 4));

        assertEquals(81, powIterative(3, 4));
        assertEquals(81, powRecursive(3, 4));
        assertEquals(1, powIterative(1234, 0));
        assertEquals(1, powRecursive(1234, 0));
    }
}