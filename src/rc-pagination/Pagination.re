module Locale = {
  /* https://github.com/react-component/pagination/blob/master/src/locale/en_US.js */
  [@bs.deriving abstract]
  type t =
    pri {
      items_per_page: string,
      jump_to: string,
      jump_to_confirm: string,
      page: string,
      prev_page: string,
      next_page: string,
      prev_5: string,
      next_5: string,
      prev_3: string,
      next_3: string,
    };
};