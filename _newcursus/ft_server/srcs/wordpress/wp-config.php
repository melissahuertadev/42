<?php
/**
 * The base configuration for WordPress
 *
 * The wp-config.php creation script uses this file during the
 * installation. You don't have to use the web site, you can
 * copy this file to "wp-config.php" and fill in the values.
 */

// ** MySQL settings - You can get this info from your web host ** //
/** The name of the database for WordPress */
define( 'DB_NAME', 'wordpress' );

/** MySQL database username */
define( 'DB_USER', 'meli' );

/** MySQL database password */
define( 'DB_PASSWORD', 'ssa' );

/** MySQL hostname */
define( 'DB_HOST', 'localhost' );

/** Database Charset to use in creating database tables. */
define( 'DB_CHARSET', 'utf8' );

/** The Database Collate type. Don't change this if in doubt. */
define( 'DB_COLLATE', '' );

/**#@+
 * Authentication Unique Keys and Salts.
 *
 * Change these to different unique phrases!
 * You can generate these using the {@link https://api.wordpress.org/secret-key/1.1/salt/ WordPress.org secret-key service}
 * You can change these at any point in time to invalidate all existing cookies. This will force all users to have to log in again.
 *
 * @since 2.6.0
 */
define('AUTH_KEY',         '+B&|iQ|C1}w-*3]d_w`w+oGjoS(x-fJFQ/j7oYV9eW|7[?U+G%+@r6,EF6+&rZ@r');
define('SECURE_AUTH_KEY',  ' 3R()l48MWlpj)a+X^TzvdW*(z`&cL+6kV&G15/ANY{[M1K-S2pSg.6wQ~N2V$}C');
define('LOGGED_IN_KEY',    '^%BAfdJcpu)F]aV&rJ1Or?(C9/i?3lU+lXjjz72Ko~3#L_frRMweCD!`+GM__OSm');
define('NONCE_KEY',        ']9r1d+S~6zQ:h]2xjbFX<^2xJ8+b#(Ry,B?A6gM|BWw!%n3XfyjV>=R7vcP.F,FO');
define('AUTH_SALT',        'F8cXPVCHDBD>?Nt1P1_EE+3!U$3oWE4{C,G1nH.:xH5<g6hC(jpN8#Re-IanX1J@');
define('SECURE_AUTH_SALT', '_g!iwx#@{;[0m>M>-p`]kQ *@3PH;jR5)@?{WMMNNBz7et*P$;8.C++l,Ok$1dh%');
define('LOGGED_IN_SALT',   '@]?J|osA5HR!`P)^W7H|qy) /5)+;7kXF}Om!d*:.upY^kKP`M5jCAoZ-dK!W5a0');
define('NONCE_SALT',       '%rH?LV|NckN+Q+n|eF7tK+[0jLY~2<+6=$9k[|V6[(t#Bkj-Z*x2w}+-G-GHJ*+@');

/**#@-*/

$table_prefix = 'wp_';

/**
 * For developers: WordPress debugging mode.
 */
define( 'WP_DEBUG', false );

/* That's all, stop editing! Happy publishing. */

/** Absolute path to the WordPress directory. */
if ( ! defined( 'ABSPATH' ) ) {
	define( 'ABSPATH', __DIR__ . '/' );
}

/** Sets up WordPress vars and included files. */
require_once ABSPATH . 'wp-settings.php';