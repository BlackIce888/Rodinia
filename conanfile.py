from conans import ConanFile, CMake

required_conan_version = ">=1.40.1"

class RodiniaConan(ConanFile):
   name = "Rodinia"
   version = "0.0.1"
   author = "Andreas Diesendorf (andiesendorf@gmail.com)"
   settings = "os", "compiler", "build_type", "arch"
   generators = "cmake"
   default_options = {"spdlog:shared": True}
   
   def requirements(self):
      self.requires("spdlog/1.9.2")
      self.requires("catch2/2.13.7")

   def imports(self):
      self.copy("*.dll", dst="bin", src="bin")
      self.copy("*.dylib*", dst="bin", src="lib")
      self.copy("*.so*", dst="bin", src="lib")
      self.copy("*.a*", dst="bin", src="lib")
      self.copy("*.h", dst="external", src="include")
      self.copy("*.hpp", dst="external", src="include")
      self.copy("*.hxx", dst="external", src="include")
      self.copy("license*", dst="external", folder=True, ignore_case=True)

   def build(self):
      cmake = CMake(self)
      cmake.configure()
      cmake.build()
      cmake.install()