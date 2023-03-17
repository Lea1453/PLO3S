
#ifndef ITKVideoCore_EXPORT_H
#define ITKVideoCore_EXPORT_H

#ifdef ITK_STATIC
#  define ITKVideoCore_EXPORT
#  define ITKVideoCore_HIDDEN
#else
#  ifndef ITKVideoCore_EXPORT
#    ifdef ITKVideoCore_EXPORTS
        /* We are building this library */
#      define ITKVideoCore_EXPORT __attribute__((visibility("default")))
#    else
        /* We are using this library */
#      define ITKVideoCore_EXPORT __attribute__((visibility("default")))
#    endif
#  endif

#  ifndef ITKVideoCore_HIDDEN
#    define ITKVideoCore_HIDDEN __attribute__((visibility("hidden")))
#  endif
#endif

#ifndef ITKVIDEOCORE_DEPRECATED
#  define ITKVIDEOCORE_DEPRECATED __attribute__ ((__deprecated__))
#endif

#ifndef ITKVIDEOCORE_DEPRECATED_EXPORT
#  define ITKVIDEOCORE_DEPRECATED_EXPORT ITKVideoCore_EXPORT ITKVIDEOCORE_DEPRECATED
#endif

#ifndef ITKVIDEOCORE_DEPRECATED_NO_EXPORT
#  define ITKVIDEOCORE_DEPRECATED_NO_EXPORT ITKVideoCore_HIDDEN ITKVIDEOCORE_DEPRECATED
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define ITKVIDEOCORE_NO_DEPRECATED
#endif

#endif
