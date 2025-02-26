class Compent {
public:
  Compent();
  Compent(Compent &&) = default;
  Compent(const Compent &) = default;
  Compent &operator=(Compent &&) = default;
  Compent &operator=(const Compent &) = default;
  ~Compent();

private:
};

Compent::Compent() {}

Compent::~Compent() {}
