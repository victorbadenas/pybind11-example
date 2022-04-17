import pytest
import sample_package as m


def test_version():
    assert m.__version__ == "0.0.1"


@pytest.mark.parametrize(
    "input_value1,input_value2,reference_result",
    [
        (1, 2, 3),
        (1.1, 2.2, 3.3),
        (1e30, 2e30, 3e30),
    ],
)
def test_add(input_value1, input_value2, reference_result):
    assert m.add(input_value1, input_value2) == pytest.approx(reference_result)


@pytest.mark.parametrize(
    "input_value1,input_value2,reference_result",
    [
        (1, 1, 0),
        (1, 2, -1),
        (2.2, 1, 1.2),
        (3e30, 2e30, 1e30),
    ],
)
def test_substract(input_value1, input_value2, reference_result):
    assert m.substract(input_value1, input_value2) == pytest.approx(reference_result)
