import static org.junit.Assert.*;

import org.junit.Test;


public class TestMath {
    @Test
    public void testMath1() {
        JunitClass junit = new JunitClass();
        int result = junit.addition(4,5);
        assertEquals(9,result);
    }
    @Test
    public void testMath() {
        JunitClass junit = new JunitClass();
        int result = junit.subtraction(5,4);
        assertEquals(1,result);
    }

}
