import unittest

# 被测试的模块
class Calculator:
    def add(self, a, b):
        return a + b

    def subtract(self, a, b):
        return a - b

# 集成测试类
class TestCalculatorIntegration(unittest.TestCase):
    def setUp(self):
        self.calculator = Calculator()

    def test_add_and_subtract(self):
        result = self.calculator.add(10, 5)
        self.assertEqual(result, 15)
        result = self.calculator.subtract(result, 3)
        self.assertEqual(result, 12)

# 运行测试
if __name__ == '__main__':
    unittest.main()
