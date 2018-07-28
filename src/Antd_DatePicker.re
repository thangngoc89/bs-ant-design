module Locale = {
  module Lang = {
    [@bs.deriving abstract]
    type t =
      pri {
        placeholder: string,
        rangePlaceholder: array(string),
        today: string,
        now: string,
        backToToday: string,
        ok: string,
        clear: string,
        month: string,
        year: string,
        timeSelect: string,
        dateSelect: string,
        weekSelect: string,
        monthSelect: string,
        yearSelect: string,
        decadeSelect: string,
        yearFormat: string,
        dateFormat: string,
        dayFormat: string,
        dateTimeFormat: string,
        monthBeforeYear: bool,
        previousMonth: string,
        nextMonth: string,
        previousYear: string,
        nextYear: string,
        previousDecade: string,
        nextDecade: string,
        previousCentury: string,
        nextCentury: string,
      };
  };

  module TimePickerLocale = {
    [@bs.deriving abstract]
    type t = pri {placeholder: string};
  };

  [@bs.deriving abstract]
  type t =
    pri {
      lang: Lang.t,
      timePickerLocale: TimePickerLocale.t,
    };
};