#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix <int> m1(5),m2(m1);
	EXPECT_EQ(m1,m2);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> b;
	TMatrix<int> *m = new TMatrix<int>;
	(*m)[0][0] = 1;
	(*m)[0][1] = 2;
	(*m)[1][1] = 1;
	b = *m;
	delete m;
	EXPECT_EQ(1, b[0][0]);
	EXPECT_EQ(2, b[0][1]);
}

TEST(TMatrix, can_get_size)
{
  TMatrix <int> m(5);
  EXPECT_EQ(5,m.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix <int> m(3);
	m[0][2] = 2;
	 EXPECT_EQ(2, m[0][2]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix <int> m(3);
	EXPECT_ANY_THROW(m[-5][2]=1);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix <int> m(3);
	EXPECT_ANY_THROW(m[5][2]=1);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	TMatrix <int> m1(3), m2(3);
	for (int i=0;i<3;i++)
		for (int j = i; j < 3; j++)
		{
			m1[i][j] = 1;
			m2[i][j] = 1;
		}
	m1 = m1;
	EXPECT_EQ(m2,m1);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	TMatrix <int> m1(3), m2(3);
	for (int i = 0; i<3; i++)
		for (int j = i; j < 3; j++)
		{
			m1[i][j] = 3;
			m2[i][j] = 1;
		}
	m1 = m2;
	EXPECT_EQ(m2,m1);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix <int> m1(3), m2(5);
	m2 = m1;
	EXPECT_EQ(3, m2.GetSize());
 
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	TMatrix <int> m1(2), m2(3);
	for (int i = 0; i<2; i++)
		for (int j = i; j < 2; j++)
			m1[i][j] = 3;
	for (int i = 0; i<3; i++)
		for (int j = i; j < 3; j++)
			m2[i][j] = 1;
	m1 = m2;
	EXPECT_EQ(m2, m1);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix <int> m1(3), m2(3);
	for (int i = 0; i<3; i++)
		for (int j = i; j < 3; j++)
		{
			m1[i][j] = 3;
			m2[i][j] = 3;
		}
	EXPECT_EQ(true, m1 == m2);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix <int> m1(3);
	for (int i = 0; i<3; i++)
		for (int j = i; j < 3; j++)
			m1[i][j] = 3;
	EXPECT_EQ(true, m1 == m1);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix <int> m1(3),m2(5);
	EXPECT_EQ(true, m1 != m2);
}


TEST(TMatrix, can_add_matrices_with_equal_size) ///Не прошел
{
	TMatrix <int> m1(3), m2(3),m3(3);
	for (int i = 0; i<3; i++)
		for (int j = i; j < 3; j++)
		{
			m1[i][j] = 1;
			m2[i][j] = 3;
			m3[i][j] = 4;
		}
	EXPECT_EQ(m3, m1 + m2);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix <int> m1(3), m2(5);
	EXPECT_ANY_THROW( m1 + m2);
}


TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix <int> m1(3), m2(3), m3(3);
	for (int i = 0; i<3; i++)
		for (int j = i; j < 3; j++)
		{
			m1[i][j] = 1;
			m2[i][j] = 3;
			m3[i][j] = 4;
		}

	EXPECT_EQ(m1, m3 - m2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix <int> m1(3), m2(5);
	EXPECT_ANY_THROW(m1 - m2);
}

