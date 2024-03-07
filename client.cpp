
#include <grpcpp/grpcpp.h>

#include <iostream>
#include <memory>
#include <string>

#include "absl/flags/flag.h"
#include "absl/flags/parse.h"
#include "helloworld.grpc.pb.h"

ABSL_FLAG(std::string, target, "localhost:50051", "Server address");

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;
using helloworld::Greeter;
using helloworld::HelloReply;
using helloworld::HelloRequest;

class GreeterClient {
   public:
    GreeterClient(std::shared_ptr<Channel> channel)
        : stub_(Greeter::NewStub(channel)) {}

    std::string SayHello(const std::string& user) {
        HelloRequest request;
        request.set_name(user);
        HelloReply reply;
        ClientContext context;

        Status status = stub_->SayHello(&context, request, &reply);

        if (status.ok()) {
            return reply.message();
        } else {
            std::cout << status.error_code() << ": " << status.error_message()
                      << std::endl;
            return "RPC failed";
        }
    }

    std::string SayHelloAgain(const std::string& user) {
        HelloRequest request;
        request.set_name(user);
        HelloReply reply;
        ClientContext context;

        Status status = stub_->SayHelloAgain(&context, request, &reply);
        if (status.ok()) {
            return reply.message();
        } else {
            std::cout << status.error_code() << ": " << status.error_message()
                      << std::endl;
            return "RPC failed";
        }
    }

   private:
    std::unique_ptr<Greeter::Stub> stub_;
};

int main(int argc, char** argv) {
    absl::ParseCommandLine(argc, argv);

    GreeterClient greeter(grpc::CreateChannel(
        absl::GetFlag(FLAGS_target);, grpc::InsecureChannelCredentials()));

    std::string reply = greeter.SayHello("world");
    std::cout << "Greeter received: " << reply << std::endl;

    reply = greeter.SayHelloAgain("world");
    std::cout << "Greeter received: " << reply << std::endl;

    return 0;
}
