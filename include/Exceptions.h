#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

class BibliothequeException : public std::exception {
protected:
  std::string message;

public:
  BibliothequeException(const std::string &msg) : message(msg) {}
  virtual const char *what() const noexcept override { return message.c_str(); }
  virtual ~BibliothequeException() {}
};

class ExceptionQuotaAtteint : public BibliothequeException {
public:
  ExceptionQuotaAtteint(const std::string &msg = "Quota d'emprunt atteint")
      : BibliothequeException(msg) {}
};

class ExceptionLivreNonDispo : public BibliothequeException {
public:
  ExceptionLivreNonDispo(const std::string &msg = "Livre non disponible")
      : BibliothequeException(msg) {}
};

#endif
