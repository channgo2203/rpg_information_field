#pragma once

#include <Eigen/Core>

#include <rpg_common/aligned.h>

namespace act_map
{
template <int K, typename T>
void eigenKXToVecKVec(const Eigen::Matrix<T, K, Eigen::Dynamic>& eigen_mat,
                      rpg::Aligned<std::vector, Eigen::Matrix<T, K, 1>>* vec)
{
  CHECK_NOTNULL(vec);
  const size_t N = static_cast<size_t>(eigen_mat.cols());
  vec->resize(N);
  for (size_t i = 0; i < N; i++)
  {
    (*vec)[i] = eigen_mat.col(static_cast<int>(i));
  }
}

template <int K, typename T>
void eigenXKToVecKVec(const Eigen::Matrix<T, Eigen::Dynamic, K>& eigen_mat,
                      rpg::Aligned<std::vector, Eigen::Matrix<T, K, 1>>* vec)
{
  CHECK_NOTNULL(vec);
  const size_t N = static_cast<size_t>(eigen_mat.rows());
  vec->resize(N);
  for (size_t i = 0; i < N; i++)
  {
    (*vec)[i] = eigen_mat.row(static_cast<int>(i));
  }
}

template <int K, typename T>
void VecKVecToEigenKX(
    const rpg::Aligned<std::vector, Eigen::Matrix<T, K, 1>>& vec,
    Eigen::Matrix<T, K, Eigen::Dynamic>* eigen_mat)
{
  CHECK_NOTNULL(eigen_mat);
  const int N = static_cast<int>(vec.size());
  eigen_mat->resize(Eigen::NoChange, N);
  for (int i = 0; i < N; i++)
  {
    eigen_mat->col(i) = vec[static_cast<size_t>(i)];
  }
}

template <int K, typename T>
void VecKVecToEigenXK(
    const rpg::Aligned<std::vector, Eigen::Matrix<T, K, 1>>& vec,
    Eigen::Matrix<T, Eigen::Dynamic, K>* eigen_mat)
{
  CHECK_NOTNULL(eigen_mat);
  const int N = static_cast<int>(vec.size());
  eigen_mat->resize(N, Eigen::NoChange);
  for (int i = 0; i < N; i++)
  {
    eigen_mat->row(i) = vec[static_cast<size_t>(i)];
  }
}

template <typename intT>
void serializeElem(const double& from, intT* to)
{
  LOG(FATAL) << "Should not enter here.";
}

template <typename intT>
void deserializeElem(const intT& from, double* to)
{
  LOG(FATAL) << "Should not enter here.";
}

template <>
void serializeElem<>(const double& from, uint32_t* to);

template <>
void serializeElem<>(const double& from, uint64_t* to);

template <>
void deserializeElem<>(const uint32_t& from, double* to);

template <>
void deserializeElem<>(const uint64_t& from, double* to);
}  // namespace act_map
