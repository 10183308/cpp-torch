#include "../include/cpptorch_cuda.h"
#include "../src/torch/Storage.h.inl"
#include "../src/torch/Tensor.h.inl"
#include "../src/torch/TensorPrint.h.inl"


template API class cpptorch::Storage<long, true>;
template API class cpptorch::Storage<float, true>;
template API class cpptorch::Storage<double, true>;
template API class cpptorch::Tensor<long, true>;
template API class cpptorch::Tensor<float, true>;
template API class cpptorch::Tensor<double, true>;

template API cpptorch::Tensor<long, true> cpptorch::abs(const cpptorch::Tensor<long, true> &t);
template API cpptorch::Tensor<float, true> cpptorch::abs(const cpptorch::Tensor<float, true> &t);
template API cpptorch::Tensor<double, true> cpptorch::abs(const cpptorch::Tensor<double, true> &t);

template API std::ostream& operator << (std::ostream &o, const cpptorch::Tensor<long, true> &m);
template API std::ostream& operator << (std::ostream &o, const cpptorch::Tensor<float, true> &m);
template API std::ostream& operator << (std::ostream &o, const cpptorch::Tensor<double, true> &m);


#include "../src/nn/BatchNormalization.h.inl"
#include "../src/nn/Concat.h.inl"
#include "../src/nn/Container.h.inl"
#include "../src/nn/Decorator.h.inl"
#include "../src/nn/DepthConcat.h.inl"
#include "../src/nn/Inception.h.inl"
#include "../src/nn/Linear.h.inl"
#include "../src/nn/MulConstant.h.inl"
#include "../src/nn/Normalize.h.inl"
#include "../src/nn/Reshape.h.inl"
#include "../src/nn/Sequential.h.inl"
#include "../src/nn/SpatialAveragePooling.h.inl"
#include "../src/nn/SpatialConvolution.h.inl"
#include "../src/nn/SpatialConvolutionMM.h.inl"
#include "../src/nn/SpatialCrossMapLRN.h.inl"
#include "../src/nn/SpatialMaxPooling.h.inl"
#include "../src/nn/SpatialReflectionPadding.h.inl"
#include "../src/nn/Sqrt.h.inl"
#include "../src/nn/Square.h.inl"
#include "../src/nn/Threshold.h.inl"
#include "../src/nn/View.h.inl"


#include "../src/builder.h.inl"
#include "../src/reader.h.inl"


cpptorch::CudaTensor cpptorch::read_cuda_tensor(const cpptorch::object *obj)
{
    object_reader<float, true> mb;
    return mb.build_tensor(obj);
}

std::shared_ptr<cpptorch::nn::CudaLayer> cpptorch::read_cuda_net(const cpptorch::object *obj)
{
    object_reader<float, true> mb;
    return std::static_pointer_cast<cpptorch::nn::Layer<float, true>>(mb.build_layer(obj));
}