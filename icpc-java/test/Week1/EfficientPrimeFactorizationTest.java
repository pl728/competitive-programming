package Week1;

import Week1.EfficientPrimeFactorization;
import org.junit.Assert;
import org.junit.Test;

import java.sql.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

import static org.junit.Assert.*;

public class EfficientPrimeFactorizationTest {

    @Test
    public void main() {
        ArrayList<Integer> expected;
        expected = new ArrayList<>(Arrays.asList(2, 3, 13, 157));
        Assert.assertEquals(expected, EfficientPrimeFactorization.epf(12246));
        expected = new ArrayList<>(Arrays.asList(2, 7, 2131));
        assertEquals(expected, EfficientPrimeFactorization.epf(29834));
        expected = new ArrayList<>(Arrays.asList(2, 17, 31, 1171));
        assertEquals(expected, EfficientPrimeFactorization.epf(1234234));
    }

}