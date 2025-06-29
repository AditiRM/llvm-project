.. title:: Welcome to the documentation of OpenMP in LLVM!

.. note::
   This document is a work in progress and most of the expected content is not
   yet available. While you can expect changes, we always welcome feedback and
   additions. Please post on the `Discourse forums (Runtimes - 
   OpenMP) <https://discourse.llvm.org/c/runtimes/openmp/35>`__..

.. toctree::
   :hidden:
   :maxdepth: 1

   LLVM/OpenMP Documentation <self>


Building LLVM/OpenMP Offloading
===============================

Building LLVM/OpenMP with offloading support is fully documented in the
:doc:`Support and FAQ <SupportAndFAQ>` page. For a quick start, we recommend
the following template.

.. code-block:: sh

  $> cd llvm-project  # The llvm-project checkout
  $> mkdir build
  $> cd build
  $> cmake ../llvm -G Ninja                                                 \
     -C ../offload/cmake/caches/Offload.cmake \ # The preset cache file
     -DCMAKE_BUILD_TYPE=<Debug|Release>   \ # Select build type
     -DCMAKE_INSTALL_PREFIX=<PATH>        \ # Where the libraries will live
  $> ninja install

LLVM/OpenMP Design & Overview
=============================

OpenMP impacts various parts of the LLVM project, from the frontends (`Clang
<https://clang.llvm.org/docs/OpenMPSupport.html>`_ and Flang), through
middle-end :ref:`optimizations <llvm_openmp_optimizations>`, up to the
multitude of available :ref:`OpenMP runtimes <openmp_runtimes>`.

A high-level overview of OpenMP in LLVM can be found :doc:`here <design/Overview>`.

.. toctree::
   :hidden:
   :maxdepth: 1

   design/Overview

OpenACC Support
===============

:doc:`OpenACC support <openacc/Overview>` is under development for
both Flang and Clang.  For this purpose, LLVM's OpenMP runtimes are
being extended to serve as OpenACC runtimes.  In some cases, Clang
supports :doc:`OpenMP extensions <openacc/OpenMPExtensions>` to make
the additional functionality also available in OpenMP applications.

.. toctree::
   :hidden:
   :maxdepth: 1

   openacc/Overview

LLVM/OpenMP Optimizations
=========================

LLVM, since `version 11 <https://releases.llvm.org/download.html#11.0.0>`_ (12 Oct
2020), has an :doc:`OpenMP-Aware optimization pass <optimizations/OpenMPOpt>`
as well as the ability to :doc:`perform "scalar optimizations" across OpenMP region
boundaries <optimizations/OpenMPUnawareOptimizations>`.

In-depth discussion of the topic can be found :doc:`here <optimizations/Overview>`.

.. toctree::
   :hidden:
   :maxdepth: 1

   optimizations/Overview

LLVM/OpenMP Optimization Remarks
================================

LLVM has an elaborate ecosystem around `analysis and optimization remarks
<https://llvm.org/docs/Remarks.html>`_ issues during
compilation. The remarks can be enabled from the clang frontend `[1]`_ `[2]`_
in various formats `[3]`_ `[4]`_ to be used by tools, i.a., `opt-viewer` or
`llvm-opt-report` (dated).

The OpenMP optimizations in LLVM have been developed with remark support as a
priority. For a list of OpenMP specific remarks and more information on them,
please refer to :doc:`remarks/OptimizationRemarks`.


.. _`[1]`: https://clang.llvm.org/docs/UsersManual.html#options-to-emit-optimization-reports
.. _`[2]`: https://clang.llvm.org/docs/ClangCommandLineReference.html#diagnostic-flags
.. _`[3]`: https://clang.llvm.org/docs/ClangCommandLineReference.html#cmdoption-clang-foptimization-record-file
.. _`[4]`: https://clang.llvm.org/docs/ClangCommandLineReference.html#cmdoption-clang1-fsave-optimization-record

+ `[1]`_ https://clang.llvm.org/docs/UsersManual.html#options-to-emit-optimization-reports
+ `[2]`_ https://clang.llvm.org/docs/ClangCommandLineReference.html#diagnostic-flags
+ `[3]`_ https://clang.llvm.org/docs/ClangCommandLineReference.html#cmdoption-clang-foptimization-record-file
+ `[4]`_ https://clang.llvm.org/docs/ClangCommandLineReference.html#cmdoption-clang1-fsave-optimization-record


.. toctree::
   :hidden:
   :maxdepth: 1

   remarks/OptimizationRemarks

OpenMP Command-Line Argument Reference
======================================
In addition to the 
`Clang command-line argument reference <https://clang.llvm.org/docs/ClangCommandLineReference.html>`_ 
we also recommend the OpenMP 
:doc:`command-line argument reference <CommandLineArgumentReference>` 
page that offers a detailed overview of options specific to OpenMP. It also 
contains a list of OpenMP offloading related command-line arguments.


.. toctree::
   :hidden:
   :maxdepth: 1

   CommandLineArgumentReference

Support, Getting Involved, and Frequently Asked Questions (FAQ)
===============================================================

Dealing with OpenMP can be complicated. For help with the setup of an OpenMP
(offload) capable compiler toolchain, its usage, and common problems, consult
the :doc:`Support and FAQ <SupportAndFAQ>` page.

We also encourage everyone interested in OpenMP in LLVM to :doc:`get involved
<SupportAndFAQ>`.


.. toctree::
   :hidden:
   :maxdepth: 1

   SupportAndFAQ

Release Notes
=============

The current (in-progress) release notes can be found :doc:`here <ReleaseNotes>` while
release notes for releases, starting with LLVM 12, will be available on `the
Download Page <https://releases.llvm.org/download.html>`_.


.. toctree::
   :hidden:
   :maxdepth: 1

   In-Progress ReleaseNotes <ReleaseNotes>
