#
# Note that the ITK/CMakeLists.txt file configures this file
#
#               CMake/CTestCustom.cmake.in
#
# to this file
#
#       ${ITK_BINARY_DIR}/CTestCustom.cmake
#
#----------------------------------------------------------------------
#
# For further details regarding this file,
# see http://www.cmake.org/Wiki/CMake_Testing_With_CTest#Customizing_CTest
#
# and
# http://www.kitware.com/blog/home/post/27
#
#----------------------------------------------------------------------

set(CTEST_CUSTOM_MAXIMUM_NUMBER_OF_WARNINGS 199)
set(CTEST_CUSTOM_MAXIMUM_NUMBER_OF_ERRORS 50)

set(CTEST_CUSTOM_TESTS_IGNORE
  
  )

set(CTEST_CUSTOM_MEMCHECK_IGNORE
  ITKCommonInDoxygenGroup;ITKFiniteDifferenceInDoxygenGroup;ITKImageFilterBaseInDoxygenGroup;ITKCurvatureFlowInDoxygenGroup;ITKImageAdaptorsInDoxygenGroup;ITKStatisticsInDoxygenGroup;ITKTransformInDoxygenGroup;ITKImageFunctionInDoxygenGroup;ITKImageGridInDoxygenGroup;ITKAnisotropicSmoothingInDoxygenGroup;ITKImageComposeInDoxygenGroup;ITKIOImageBaseInDoxygenGroup;ITKMeshInDoxygenGroup;ITKSpatialObjectsInDoxygenGroup;ITKImageStatisticsInDoxygenGroup;ITKPathInDoxygenGroup;ITKImageIntensityInDoxygenGroup;ITKImageLabelInDoxygenGroup;ITKThresholdingInDoxygenGroup;ITKConnectedComponentsInDoxygenGroup;ITKMathematicalMorphologyInDoxygenGroup;ITKLabelMapInDoxygenGroup;ITKBinaryMathematicalMorphologyInDoxygenGroup;ITKNarrowBandInDoxygenGroup;ITKDistanceMapInDoxygenGroup;ITKQuadEdgeMeshInDoxygenGroup;ITKFastMarchingInDoxygenGroup;ITKImageCompareInDoxygenGroup;ITKSmoothingInDoxygenGroup;ITKImageGradientInDoxygenGroup;ITKImageSourcesInDoxygenGroup;ITKImageFeatureInDoxygenGroup;ITKOptimizersInDoxygenGroup;ITKSignedDistanceFunctionInDoxygenGroup;ITKLevelSetsInDoxygenGroup;ITKAntiAliasInDoxygenGroup;ITKPolynomialsInDoxygenGroup;ITKBiasCorrectionInDoxygenGroup;ITKBioCellInDoxygenGroup;ITKClassifiersInDoxygenGroup;ITKColormapInDoxygenGroup;ITKFFTInDoxygenGroup;ITKConvolutionInDoxygenGroup;ITKDeconvolutionInDoxygenGroup;ITKDeformableMeshInDoxygenGroup;ITKDenoisingInDoxygenGroup;ITKDiffusionTensorImageInDoxygenGroup;ITKDisplacementFieldInDoxygenGroup;ITKEigenInDoxygenGroup;ITKIOXMLInDoxygenGroup;ITKIOSpatialObjectsInDoxygenGroup;ITKRegistrationCommonInDoxygenGroup;ITKFEMInDoxygenGroup;ITKPDEDeformableRegistrationInDoxygenGroup;ITKFEMRegistrationInDoxygenGroup;ITKGPUCommonInDoxygenGroup;ITKGPUFiniteDifferenceInDoxygenGroup;ITKGPUAnisotropicSmoothingInDoxygenGroup;ITKGPUImageFilterBaseInDoxygenGroup;ITKGPURegistrationCommonInDoxygenGroup;ITKGPUPDEDeformableRegistrationInDoxygenGroup;ITKGPUSmoothingInDoxygenGroup;ITKGPUThresholdingInDoxygenGroup;ITKIOBMPInDoxygenGroup;ITKIOBioRadInDoxygenGroup;ITKIOCSVInDoxygenGroup;ITKIOGDCMInDoxygenGroup;ITKIOIPLInDoxygenGroup;ITKIOGEInDoxygenGroup;ITKIOGIPLInDoxygenGroup;ITKIOHDF5InDoxygenGroup;ITKIOJPEGInDoxygenGroup;ITKIOTIFFInDoxygenGroup;ITKIOLSMInDoxygenGroup;ITKIOMRCInDoxygenGroup;ITKIOMeshInDoxygenGroup;ITKIOMetaInDoxygenGroup;ITKIONIFTIInDoxygenGroup;ITKIONRRDInDoxygenGroup;ITKIOPNGInDoxygenGroup;ITKIORAWInDoxygenGroup;ITKIOSiemensInDoxygenGroup;ITKIOStimulateInDoxygenGroup;ITKIOTransformBaseInDoxygenGroup;ITKIOTransformHDF5InDoxygenGroup;ITKIOTransformInsightLegacyInDoxygenGroup;ITKIOTransformMatlabInDoxygenGroup;ITKIOVTKInDoxygenGroup;ITKImageFusionInDoxygenGroup;ITKImageNoiseInDoxygenGroup;ITKKLMRegionGrowingInDoxygenGroup;ITKLabelVotingInDoxygenGroup;ITKLevelSetsv4InDoxygenGroup;ITKMarkovRandomFieldsClassifiersInDoxygenGroup;ITKOptimizersv4InDoxygenGroup;ITKMetricsv4InDoxygenGroup;ITKNeuralNetworksInDoxygenGroup;ITKQuadEdgeMeshFilteringInDoxygenGroup;ITKRegionGrowingInDoxygenGroup;ITKRegistrationMethodsv4InDoxygenGroup;ITKSpatialFunctionInDoxygenGroup;ITKVTKInDoxygenGroup;ITKVoronoiInDoxygenGroup;ITKWatershedsInDoxygenGroup;ITKReviewInDoxygenGroup;ITKTestKernelInDoxygenGroup;ITKVideoCoreInDoxygenGroup;ITKVideoFilteringInDoxygenGroup;ITKVideoIOInDoxygenGroup
  )

set(CTEST_EXTRA_COVERAGE_GLOB
  Source/.*/*.h
  Source/.*/*.txx
  Source/.*/*.cxx
  )

set(CTEST_CUSTOM_COVERAGE_EXCLUDE
 ${CTEST_CUSTOM_COVERAGE_EXCLUDE}

 # Exclude try_compile sources from coverage results:
 "/CMakeFiles/CMakeTmp/"

 # Exclude files from the Examples directories
 ".*/Examples/.*"

 # Exclude files from the Testing directories
 ".*/test/.*"
 ".*/Testing/.*"

 # Exclude files from the ThirdParty Utilities directories
 ".*/ThirdParty/.*"
 ".*/Utilities/.*"

 # Exclude files from the Wrapping directories
 ".*/Wrapping/.*"
 )

set(CTEST_CUSTOM_WARNING_EXCEPTION
  ${CTEST_CUSTOM_WARNING_EXCEPTION}
  "warning LNK4221.*no public symbols found"
  "ranlib:.*file:.*has no symbols"
  "ranlib: file: .+ has no symbols"
  "libtool:.*file:.*has no symbols"
  "ipo: warning #11053"
  "ipo: warning #11053"
  "vxl.core.vnl.algo"
  "vxl.core.vnl"
  "vxl.v3p.netlib"
  "itkjpeg"
  "usr.include.stdint.h"
  "Warning itk::Statistics::Histogram"
  "itkIOCommonTest.cxx:.*warning:.* is deprecated"
  "/usr/bin/ld: warning: libnetcdf.so.3, needed by.*may conflict with libnetcdf.so.4"
  "itkQuadEdgeMeshEdgeMergeDecimationFilter.hxx:.*warning: unused parameter.*iEdge.*"
  "vnl_diag_matrix.h"
  "WARNING non-zero return value in ctest"
  "Warning.*Anachronism.*"
  "attempted multiple inclusion of file"
  "warning LNK4221: This object file does not define any previously undefined public symbols"
  ".*[/\\\\][Mm]odules[/\\\\][Tt]hird[Pp]arty[/\\\\][Dd][Ii][Cc][Oo][Mm][Pp]arser[/\\\\].*[Ww]arning.*"
  ".*[/\\\\][Mm]odules[/\\\\][Tt]hird[Pp]arty[/\\\\][Ee]xpat[/\\\\].*[Ww]arning.*"
  ".*[/\\\\][Mm]odules[/\\\\][Tt]hird[Pp]arty[/\\\\][Jj][Pp][Ee][Gg][/\\\\].*[Ww]arning.*"
  ".*[/\\\\][Mm]odules[/\\\\][Tt]hird[Pp]arty[/\\\\][Kk][Ww][Ss]ys[/\\\\].*[Ww]arning.*"
  ".*[/\\\\][Mm]odules[/\\\\][Tt]hird[Pp]arty[/\\\\][Mm]eta[Ii][Oo][/\\\\].*[Ww]arning.*"
  ".*[/\\\\][Mm]odules[/\\\\][Tt]hird[Pp]arty[/\\\\][Nn]etlib[/\\\\].*[Ww]arning.*"
  ".*[/\\\\][Mm]odules[/\\\\][Tt]hird[Pp]arty[/\\\\][Nn][Ii][Ff][Tt][Ii][/\\\\].*[Ww]arning.*"
  ".*[/\\\\][Mm]odules[/\\\\][Tt]hird[Pp]arty[/\\\\][Oo]pen[Jj][Pp][Ee][Gg][/\\\\].*[Ww]arning.*"
  ".*[/\\\\][Mm]odules[/\\\\][Tt]hird[Pp]arty[/\\\\][Pp][Nn][Gg][/\\\\].*[Ww]arning.*"
  ".*[/\\\\][Mm]odules[/\\\\][Tt]hird[Pp]arty[/\\\\][Tt][Ii][Ff][Ff][/\\\\].*[Ww]arning.*"
  ".*[/\\\\][Mm]odules[/\\\\][Tt]hird[Pp]arty[/\\\\][Vv][Nn][Ll][/\\\\].*[Ww]arning.*"
  ".*[/\\\\][Mm]odules[/\\\\][Tt]hird[Pp]arty[/\\\\][Vv][Nn][Ll][Ii]nstantiation[/\\\\].*[Ww]arning.*"
  ".*[/\\\\][Mm]odules[/\\\\][Tt]hird[Pp]arty[/\\\\][Zz][Ll][Ii][Bb][/\\\\].*[Ww]arning.*"
  ".*Microsoft.*include.*win.*.h.*[Ww]arning.*"
  ".*include.opencv2.*warning.*"
  ".*core.vidl.*warning.*"
  ".*core.vnl.vnl_matrix_fixed.h.*warning.*"
  # ExternalProject: Git writes status to stderr
  "Cloning into.*"
  "Note: checking out.*"
  "HEAD is now at.*"
  # FFTW ExternalProject
  ".*fftw[fd]/src/fftw[fd]./*"
  "libtool: install: warning: relinking .libfftw3f?_threads.la."

  # Ignore clang's summary warning, assuming prior text has matched some
  # other warning expression:
  "[0-9,]+ warnings? generated."

  # The PCRE, SWIG, and third party builds for wrapping.
  ".*/PCRE/.*"
  ".*/swig/.*"
  ".*parser.py.*"
  "checking maximum warning verbosity option.*"

  "warning: Using 'getpwnam' in statically linked applications requires at runtime the shared libraries"
  )

if(APPLE)
  set(CTEST_CUSTOM_WARNING_EXCEPTION
    ${CTEST_CUSTOM_WARNING_EXCEPTION}
    "warning -.: directory name .* does not exist"
    "ld.*warning.*duplicate dylib.*"
    )
endif()

set(CTEST_CUSTOM_ERROR_EXCEPTION
  # Emscripten
  ".*WARNING  root: emcc: cannot find library.*"
  )
