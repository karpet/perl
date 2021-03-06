#!perl

use strict;
use warnings;

use Test::More tests => 2;
use HTTP::Tiny;

my @accessors = qw(
  agent default_headers local_address max_redirect max_size proxy timeout SSL_options verify_SSL
);
my @methods   = qw(
  new get head put post delete post_form request mirror www_form_urlencode
);

my %api;
@api{@accessors} = (1) x @accessors;
@api{@methods} = (1) x @methods;

can_ok('HTTP::Tiny', @methods, @accessors);

my @extra =
  grep {! $api{$_} }
  grep { $_ !~ /\A_/ }
  grep {; no strict 'refs'; *{"HTTP::Tiny::$_"}{CODE} }
  sort keys %HTTP::Tiny::;

ok( ! scalar @extra, "No unexpected subroutines defined" )
  or diag "Found: @extra";
