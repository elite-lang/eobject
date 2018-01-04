from conans import ConanFile, CMake
import os

# This easily allows to copy the package in other user or channel
channel = os.getenv("CONAN_CHANNEL", "ci")
username = os.getenv("CONAN_USERNAME", "sunxfancy")

class HelloReuseConan(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    requires = "eobject/0.1.1@%s/%s" % (username, channel)
    generators = "cmake"
    build_policy = "missing"

    def build(self):
        self.cmake = CMake(self)
        self.cmake.configure(source_dir=self.conanfile_directory, build_dir="./")
        self.cmake.build()

    def test(self):
        self.run(os.sep.join([".","bin", "libtest"]))

    def imports(self):
        self.copy(pattern="*.dll", dst="bin", src="bin")
        self.copy(pattern="*.so*", dst="bin", src="lib")
        self.copy(pattern="*.dylib", dst="bin", src="lib")
