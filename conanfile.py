from conans import ConanFile, CMake, MSBuild

required_conan_version = ">=1.40.1"

class RodiniaConan(ConanFile):
   name = "Rodinia"
   version = "0.0.2"
   author = "Andreas Diesendorf (andiesendorf@gmail.com)"
   description = "Rodinia Game Engine"
   settings = "os", "compiler", "build_type", "arch"
   generators = "cmake_find_package", "cmake_paths", "visual_studio"#, "virtualrunenv"
   default_options = {"spdlog:shared": True}
   
   def requirements(self):
      self.requires("spdlog/1.9.2")
      self.requires("catch2/2.13.7")

   def imports(self):
      self.copy("*.dll", dst="bin", src="bin")
      self.copy("*.dylib*", dst="bin", src="lib")
      self.copy("*.so*", dst="bin", src="lib")
      #self.copy("*.a*", dst="bin", src="lib")
      #self.copy("*.h", dst="external", src="include")
      #self.copy("*.hpp", dst="external", src="include")
      #self.copy("*.hxx", dst="external", src="include")
      #self.copy("license*", dst="external", folder=True, ignore_case=True)

   def build(self):
      cmake = CMake(self, generator="Ninja")
      cmake.configure()
      cmake.build()
      cmake.install()
      cmake.test()