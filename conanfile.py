from conans import ConanFile, CMake

class LmeComplexityConan(ConanFile):
   name = "lme_complexity"
   version = "1.0.0"
   author = "maximlomovtsev (maximlomovtsev@gmail.com)"
   settings = "os", "compiler", "build_type", "arch"
   generators = "cmake"

   requires = [
      "cxxopts/3.0.0"
   ]

   def build(self):
      cmake = CMake(self)
      cmake.configure()
      cmake.build()